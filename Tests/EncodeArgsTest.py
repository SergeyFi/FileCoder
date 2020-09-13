import subprocess
import settings
import os


testName = 'Encode test with args'


def run_encode_test():
    result = subprocess.run([settings.fileCoder, 'encode', '-F', settings.fileTarget,
                             '-C', settings.fileCipherCustom,
                             '-K', settings.fileKeyCustom], stdout=subprocess.PIPE)

    result.stdout.decode("UTF-8")

    targetSize = os.path.getsize(settings.fileTarget)
    cipherSize = os.path.getsize(settings.fileCipherCustom)
    keySize = os.path.getsize(settings.fileKeyCustom)

    if targetSize == cipherSize == keySize:
        return True
    else:
        return False
