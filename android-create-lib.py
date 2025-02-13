import os
import shutil

def should_copy(entry_name: str) -> bool:
    return not entry_name.startswith("MacOS")

def copy_directory_recursive(src_dir: str, dest_dir: str) -> None:
    if not os.path.exists(src_dir):
        print(f"Source directory '{src_dir}' does not exist.")
        return

    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)

    for entry in os.listdir(src_dir):
        src_entry_path = os.path.join(src_dir, entry)
        dest_entry_path = os.path.join(dest_dir, entry)

        if should_copy(entry):
            if os.path.isdir(src_entry_path):
                # Recursively copy the directory
                copy_directory_recursive(src_entry_path, dest_entry_path)
            else:
                # Copy the file
                shutil.copy2(src_entry_path, dest_entry_path)
        else:
            print(f"Skipping '{src_entry_path}' as per the rule.")

if __name__ == "__main__":

    android_lib__dir_name = "../android-lib"

    # Delete destination directory if it exists
    if os.path.exists(android_lib__dir_name):
        shutil.rmtree(android_lib__dir_name)


    os.mkdir(android_lib__dir_name)
    print("Directory", android_lib__dir_name, "created")

    source_directory = "GATE/src"
    copy_directory_recursive(source_directory, android_lib__dir_name)
    print(f"Copy completed from '{source_directory}' to '{android_lib__dir_name}'.")
