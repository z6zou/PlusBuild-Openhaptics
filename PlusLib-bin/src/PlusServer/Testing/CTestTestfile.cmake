# CMake generated Testfile for 
# Source directory: C:/Project/PlusB-bin/PlusLib/src/PlusServer/Testing
# Build directory: C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer/Testing
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(PlusServer "C:/Project/PlusB-bin/bin/vtkPlusServerTest" "--server-config-file=C:/Project/PlusB-bin/PlusLibData/ConfigFiles/Testing/PlusDeviceSet_OpenIGTLinkTestServer.xml" "--testing-config-file=C:/Project/PlusB-bin/PlusLibData/ConfigFiles/Testing/PlusDeviceSet_OpenIGTLinkTestClient.xml")
set_tests_properties(PlusServer PROPERTIES  FAIL_REGULAR_EXPRESSION "ERROR;WARNING" _BACKTRACE_TRIPLES "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Testing/CMakeLists.txt;10;ADD_TEST;C:/Project/PlusB-bin/PlusLib/src/PlusServer/Testing/CMakeLists.txt;0;")
add_test(PlusServerOpenIGTLinkCommandsTest "C:/Project/PlusB-bin/bin/PlusServerRemoteControl" "--server-config-file=C:/Project/PlusB-bin/PlusLibData/ConfigFiles/Testing/PlusDeviceSet_OpenIGTLinkCommandsTest.xml" "--run-tests")
set_tests_properties(PlusServerOpenIGTLinkCommandsTest PROPERTIES  FAIL_REGULAR_EXPRESSION "ERROR;WARNING" TIMEOUT "90" _BACKTRACE_TRIPLES "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Testing/CMakeLists.txt;21;ADD_TEST;C:/Project/PlusB-bin/PlusLib/src/PlusServer/Testing/CMakeLists.txt;0;")
