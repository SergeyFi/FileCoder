import subprocess
import settings
import os


testName = 'Encode simply test'


def run_encode_test():
    result = subprocess.run([settings.fileCoder, 'encode', '-F', settings.fileTarget], stdout=subprocess.PIPE)

    result.stdout.decode("UTF-8")

    try:
        targetSize = os.path.getsize(settings.fileTarget)
        cipherSize = os.path.getsize(settings.fileCipherDefault)
        keySize = os.path.getsize(settings.fileKeyDefault)

        if targetSize == cipherSize == keySize:
            return True
        else:
            return False

    except FileNotFoundError as not_found:
        print('File', not_found.filename, 'does not exist.')