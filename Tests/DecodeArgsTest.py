import subprocess
import settings
import filecmp


testName = 'Decode test with args'


def run_decode_test():
    result = subprocess.run([settings.fileCoder, 'decode', '-F', settings.fileDecodedCustom,
                             '-C', settings.fileCipherCustom,
                             '-K', settings.fileKeyCustom], stdout=subprocess.PIPE)

    result.stdout.decode("UTF-8")

    try:
        if filecmp.cmp(settings.fileTarget, settings.fileDecodedCustom, False):
            return True
        else:
            return False

    except FileNotFoundError as not_found:
        print('File', not_found.filename, 'does not exist.')
