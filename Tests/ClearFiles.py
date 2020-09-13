import os


def clear_files(*files_path):
    for path in files_path:
        os.remove(path)
