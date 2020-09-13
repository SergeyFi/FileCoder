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

    targetSize = os.path.getsize(settings.fileTarget)
    decodedFileSize = os.path.getsize(settings.fileDecodedDefault)

    if filecmp.cmp(settings.fileTarget, settings.fileDecodedDefault, False):
        return True
    else:
        return False
