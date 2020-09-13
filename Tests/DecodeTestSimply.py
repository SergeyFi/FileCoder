import subprocess
import settings
import os
import filecmp


testName = 'Decode simply test'


def run_encode_test():
    result = subprocess.run([settings.fileCoder, 'decode',
                             '-F', settings.fileTarget,
                             '-C', settings.fileCipherDefault,
                             '-K', settings.fileKeyDefault, '-P'], stdout=subprocess.PIPE)

    result.stdout.decode("UTF-8")

    try:
        if filecmp.cmp(settings.fileTarget, settings.fileDecodedDefault, False):
            return True
        else:
            return False

    except FileNotFoundError as not_found:
        print('File', not_found.filename, 'does not exist.')
