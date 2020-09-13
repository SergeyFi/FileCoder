import os


def clear_files(file_decoded_path, file_cipher_path, file_key_path):
    os.remove(file_decoded_path)
    os.remove(file_cipher_path)
    os.remove(file_key_path)
