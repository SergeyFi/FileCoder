import subprocess
import settings
import os
import ClearFiles
import filecmp

result = subprocess.run([settings.fileCoder, 'decode',
                         '-F', settings.fileTarget,
                         '-C', settings.fileCipherDefault,
                         '-K', settings.fileKeyDefault, '-P'], stdout=subprocess.PIPE)

result.stdout.decode("UTF-8")

targetSize = os.path.getsize(settings.fileTarget)
decodedFileSize = os.path.getsize(settings.fileDecodedDefault)

if filecmp.cmp(settings.fileTarget, settings.fileDecodedDefault, False):
    print(settings.ok)
else:
    print(settings.bad)

ClearFiles.clear_files(settings.fileDecodedDefault, settings.fileCipherDefault, settings.fileKeyDefault)