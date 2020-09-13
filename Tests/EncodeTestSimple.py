import subprocess
import settings
import os

result = subprocess.run([settings.fileCoder, 'encode', '-F', settings.fileTarget], stdout=subprocess.PIPE)

result.stdout.decode("UTF-8")

targetSize = os.path.getsize(settings.fileTarget)
cipherSize = os.path.getsize(settings.fileCipherDefault)
keySize = os.path.getsize(settings.fileKeyDefault)

if targetSize == cipherSize == keySize:
    print(settings.ok)
else:
    print(settings.bad)
