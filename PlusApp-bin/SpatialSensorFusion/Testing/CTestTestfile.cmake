# CMake generated Testfile for 
# Source directory: C:/Project/PlusB-bin/PlusApp/SpatialSensorFusion/Testing
# Build directory: C:/Project/PlusB-bin/PlusApp-bin/SpatialSensorFusion/Testing
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(SpatialSensorFusionTest "C:/Project/PlusB-bin/bin/SpatialSensorFusion" "--ahrs-algo=MADGWICK_IMU" "--ahrs-algo-gain" "1.5" "--initial-gain" "1" "--initial-repeated-frame-number=1000" "--input-seq-file=C:/Project/PlusB-bin/PlusLibData/TestImages/SpatialSensorFusionTestInput.igs.mha" "--output-seq-file=C:/Project/PlusB-bin/PlusLibData/TestImages/SpatialSensorFusionTestOutput.igs.mha" "--baseline-seq-file=C:/Project/PlusB-bin/PlusLibData/TestImages/SpatialSensorFusionTestBaseline.igs.mha" "--west-axis-index=1")
set_tests_properties(SpatialSensorFusionTest PROPERTIES  FAIL_REGULAR_EXPRESSION "ERROR;WARNING" _BACKTRACE_TRIPLES "C:/Project/PlusB-bin/PlusApp/SpatialSensorFusion/Testing/CMakeLists.txt;5;ADD_TEST;C:/Project/PlusB-bin/PlusApp/SpatialSensorFusion/Testing/CMakeLists.txt;0;")
