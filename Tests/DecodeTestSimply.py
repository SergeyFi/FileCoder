import subprocess
import settings
import os

result = subprocess.run([settings.fileCoder, 'decode',
                         '-F', settings.fileTarget,
                         '-C', settings.fileCipherDefault,
                         '-K', settings.fileKeyDefault, '-P'], stdout=subprocess.PIPE)

result.stdout.decode("UTF-8")

targetSize = os.path.getsize(settings.fileTarget)
decodedFileSize = os.path.getsize(settings.fileDecodedDefault)

if targetSize == decodedFileSize:
    print(settings.ok)
else:
    print(settings.bad)