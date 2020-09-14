import settings
import printResult
import EncodeTestSimple
import DecodeTestSimply
import EncodeArgsTest
import ClearFiles
import VersionTest
import DecodeArgsTest

printResult.print_result(VersionTest.testName, VersionTest.run_version_test())

printResult.print_result(EncodeTestSimple.testName, EncodeTestSimple.run_encode_test())

printResult.print_result(DecodeTestSimply.testName, DecodeTestSimply.run_encode_test())

ClearFiles.clear_files(settings.fileDecodedDefault, settings.fileCipherDefault, settings.fileKeyDefault)

printResult.print_result(EncodeArgsTest.testName, EncodeArgsTest.run_encode_test())

printResult.print_result(DecodeArgsTest.testName, DecodeArgsTest.run_decode_test())

ClearFiles.clear_files(settings.fileCipherCustom, settings.fileKeyCustom, settings.fileDecodedCustom)
