import settings
import printResult
import EncodeTestSimple
import DecodeTestSimply
import ClearFiles


printResult.print_result(EncodeTestSimple.testName, EncodeTestSimple.run_encode_test())

printResult.print_result(DecodeTestSimply.testName, DecodeTestSimply.run_encode_test())

ClearFiles.clear_files(settings.fileDecodedDefault, settings.fileCipherDefault, settings.fileKeyDefault)
