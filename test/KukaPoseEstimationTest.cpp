// Copyright 2012-2017 CNRS-UM LIRMM, CNRS-AIST JRL
//
// This file is part of RBDyn.
//
// RBDyn is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RBDyn is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with RBDyn.  If not, see <http://www.gnu.org/licenses/>.

// includes
// std
#include <iostream>

// boost
#define BOOST_TEST_MODULE KukaPoseEstimationTest  // master test suite name
#include <boost/test/unit_test.hpp>
#include <boost/math/constants/constants.hpp>


#include <string>
#include <tuple>
#include <boost/format.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "camodocal/EigenUtils.h"

#include "grl/flatbuffer/ParseflatbuffertoCSV.hpp"
#include "grl/time.hpp"

// SpaceVecAlg
// https://github.com/jrl-umi3218/SpaceVecAlg
#include <SpaceVecAlg/SpaceVecAlg>

// RBDyn
// https://github.com/jrl-umi3218/RBDyn
#include <RBDyn/Body.h>
#include <RBDyn/Joint.h>
#include <RBDyn/MultiBody.h>
#include <RBDyn/MultiBodyConfig.h>
#include <RBDyn/MultiBodyGraph.h>
#include <RBDyn/FK.h>

// mc_rbdyn_urdf
// https://github.com/jrl-umi3218/mc_rbdyn_urdf
#include <mc_rbdyn_urdf/urdf.h>
#include "kukaiiwaURDF.h"

#include <boost/filesystem.hpp>

// const double PI = 3.14159265359;
const double RadtoDegree = 180/3.14159265359;
const double MeterToMM = 1000;

// "/home/chunting/src/V-REP_PRO_EDU_V3_4_0_Linux/";
std::string currentPath = boost::filesystem::current_path().string();

std::string foldtimestamp = current_date_and_time_string();

std::string kukaBinaryfile = currentPath + "2018_02_26_14_23_14_Kukaiiwa.iiwa";
std::string KUKA_TimeEvent_CSVfilename = currentPath + foldtimestamp + "/KUKA_TimeEvent.csv";
std::string KUKA_Joint_CSVfilename = currentPath + foldtimestamp + "/KUKA_Joint.csv";
std::string KUKA_Pose_CSVfilename = currentPath + foldtimestamp + "/KUKA_Pose.csv";




int main(int argc, char* argv[])
{

	// namespace cst = boost::math::constants;
    // auto strRobot = mc_rbdyn_urdf::rbdyn_from_urdf(XYZSarmUrdf);
    // rbd::MultiBody mb = strRobot.mb;
    // rbd::MultiBodyConfig mbc(mb);
    // rbd::MultiBodyGraph mbg(strRobot.mbg);
    // std::size_t nrJoints = mbg.nrJoints();
    // std::vector<std::string> jointNames;
    // std::cout<<"Joint Size: "<< nrJoints << std::endl;
    // fbs_tk::Root<grl::flatbuffer::KUKAiiwaStates> kukaStatesP = fbs_tk::open_root<grl::flatbuffer::KUKAiiwaStates>(kukaBinaryfile);

    // grl::MatrixXd timeEventM_Kuka = grl::getTimeStamp(kukaStatesP,grl::kuka_tag());
    // grl::regularizeTimeEvent(timeEventM_Kuka);

    // Eigen::MatrixXd jointAngles = grl::getAllJointAngles(kukaStatesP);
    // std::vector<std::string> Kuka_Joint_Labels = grl::getLabels(grl::LabelsType::Joint);
    // jointAngles = RadtoDegree*jointAngles;
    // if(jointAngles.rows() == timeEventM_Kuka.rows()){
    //      grl::writeMatrixToCSV(KUKA_Joint_CSVfilename, Kuka_Joint_Labels, timeEventM_Kuka, jointAngles);
    // }


    // std::size_t row_size = jointAngles.rows();
    // std::size_t body_size = mbc.bodyPosW.size();
    // /// The translation and Euler angles in world coordinate.
    // Eigen::MatrixXd poseEE(row_size,6);

    // for(int rowIdx=0; rowIdx<row_size; rowIdx++){
    //     Eigen::VectorXd oneStateJointPosition = jointAngles.row(rowIdx);
    //     int jointIdx = 0;
    //     for(int jointIndex = 0; jointIndex< nrJoints; jointIndex++) {
    //         const auto & joint = strRobot.mb.joint(jointIndex);
    //         jointNames.push_back(joint.name());
    //         // std::cout << "Joint Name: " << joint.name() << "     Size: " << mbc.q[jointIndex].size() << std::endl;
    //         if (mbc.q[jointIndex].size() > 0) {
    //             mbc.q[jointIndex][0] = oneStateJointPosition[jointIdx];
    //             jointIdx++;
    //         }
    //     }
    //     rbd::forwardKinematics(mb, mbc);
    //     sva::PTransformd pos = mbc.bodyPosW[body_size-1];
    //     Eigen::Matrix3d E ;    // rotation

    //     Eigen::Vector3d r ;    // translation
    //     E = pos.rotation();
    //     r = MeterToMM*pos.translation();
    //     Eigen::Vector3d eulerAngleEigen = RadtoDegree*E.eulerAngles(0,1,2);
    //     Eigen::Quaterniond q(E);
    //     Eigen::RowVectorXd pose(6);
    //     pose << r.transpose(), eulerAngleEigen.transpose();
    //     poseEE.row(rowIdx) = pose;
    //     // std::cout << "-----------------------------------" << std::endl;
    //     // std::cout << "Rotation:\n " << E << std::endl
    //     //           << "Translation:\n" << r <<std::endl;


    // }
    // // std::cout << poseEE << std::endl;
    // //grl::writeEEPoseToCSV(KUKA_TimeEvent_CSVfilename, kuka_device_time, kuka_local_request_time, kuka_local_receive_time, poseEE);
    // grl::writeMatrixToCSV(KUKA_Pose_CSVfilename, Kuka_Joint_Labels, timeEventM_Kuka, jointAngles);

  return 0;
}