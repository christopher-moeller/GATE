#include "MacOSOpenGLNativeWindow.h"
#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>

@interface MetalWindowObjC : NSObject
@property (nonatomic, strong) NSWindow *window;
@property (nonatomic, strong) NSOpenGLContext *glContext;
@end

@implementation MetalWindowObjC
@end

MacOSOpenGLNativeWindow::MacOSOpenGLNativeWindow(int width, int height, const char* title) {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];

        NSRect frame = NSMakeRect(100, 100, width, height);
        NSWindow *nsWindow = [[NSWindow alloc] initWithContentRect:frame
                                                         styleMask:(NSWindowStyleMaskTitled |
                                                                    NSWindowStyleMaskClosable |
                                                                    NSWindowStyleMaskResizable)
                                                           backing:NSBackingStoreBuffered
                                                             defer:NO];

        [nsWindow setTitle:[NSString stringWithUTF8String:title]];
        [nsWindow center];

        // OpenGL Context
        NSOpenGLPixelFormatAttribute attributes[] = {
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
            NSOpenGLPFAColorSize, 24,
            NSOpenGLPFADepthSize, 16,
            NSOpenGLPFAStencilSize, 8,
            NSOpenGLPFAAccelerated,
            NSOpenGLPFADoubleBuffer,
            0
        };

        NSOpenGLPixelFormat *pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attributes];
        NSOpenGLContext *glContext = [[NSOpenGLContext alloc] initWithFormat:pixelFormat shareContext:nil];
        [glContext makeCurrentContext];

        // Store in Objective-C++ Wrapper
        MetalWindowObjC* objCWindow = [[MetalWindowObjC alloc] init];
        objCWindow.window = nsWindow;
        objCWindow.glContext = glContext;

        // Assign to opaque pointers
        this->window = (__bridge_retained void*)objCWindow;
        this->glContext = (__bridge_retained void*)glContext;

        [nsWindow makeKeyAndOrderFront:nil];
    }
}

MacOSOpenGLNativeWindow::~MacOSOpenGLNativeWindow() {
    MetalWindowObjC* objCWindow = (__bridge_transfer MetalWindowObjC*)this->window;
    objCWindow.window = nil; // Release window
    objCWindow.glContext = nil; // Release OpenGL context
}

void MacOSOpenGLNativeWindow::pollEvents() {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        NSEvent *event;
        while ((event = [app nextEventMatchingMask:NSEventMaskAny
                                         untilDate:nil
                                            inMode:NSDefaultRunLoopMode
                                           dequeue:YES])) {
            [app sendEvent:event];
        }
    }
}

void MacOSOpenGLNativeWindow::swapBuffers() {
    @autoreleasepool {
        MetalWindowObjC* objCWindow = (__bridge MetalWindowObjC*)this->window;
        [objCWindow.glContext flushBuffer];
    }
}

