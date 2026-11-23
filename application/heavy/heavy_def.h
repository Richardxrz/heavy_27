#include "message_center.h"
#include "robot_def.h"

static Publisher_t *chassis_pub;  // 用于发布底盘的数据
static Subscriber_t *chassis_sub; // 用于订阅底盘的控制命令

static Chassis_Ctrl_Cmd_s chassis_cmd_recv;         // 底盘接收到的控制命令
static Chassis_Upload_Data_s chassis_feedback_data; // 底盘回传的反馈数据

static void MecanumKinematicsCalculate() {}

static void SetMotorReference() {}

static void UpdateChassisFeedback() {}

void MecanumChassisInit() {}

void MecanumChassisTask() {
  // 获取新的控制信息
  SubGetMessage(chassis_sub, &chassis_cmd_recv);

  // 运动学解算
  MecanumKinematicsCalculate();

  // 设置电机参考值
  SetMotorReference();

  // 反馈数据更新
  UpdateChassisFeedback();

  // 发布反馈数据
  PubPushMessage(chassis_pub, (void *)&chassis_feedback_data);
}
