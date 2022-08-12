
"use strict";

let ClearWaypoints = require('./ClearWaypoints.js')
let SetMBSMControllerParams = require('./SetMBSMControllerParams.js')
let SwitchToAutomatic = require('./SwitchToAutomatic.js')
let SetPIDParams = require('./SetPIDParams.js')
let GetSMControllerParams = require('./GetSMControllerParams.js')
let Hold = require('./Hold.js')
let ResetController = require('./ResetController.js')
let StartTrajectory = require('./StartTrajectory.js')
let GetWaypoints = require('./GetWaypoints.js')
let InitWaypointSet = require('./InitWaypointSet.js')
let SwitchToManual = require('./SwitchToManual.js')
let InitWaypointsFromFile = require('./InitWaypointsFromFile.js')
let GetMBSMControllerParams = require('./GetMBSMControllerParams.js')
let GoTo = require('./GoTo.js')
let GoToIncremental = require('./GoToIncremental.js')
let InitRectTrajectory = require('./InitRectTrajectory.js')
let GetPIDParams = require('./GetPIDParams.js')
let InitCircularTrajectory = require('./InitCircularTrajectory.js')
let IsRunningTrajectory = require('./IsRunningTrajectory.js')
let SetSMControllerParams = require('./SetSMControllerParams.js')
let InitHelicalTrajectory = require('./InitHelicalTrajectory.js')
let AddWaypoint = require('./AddWaypoint.js')

module.exports = {
  ClearWaypoints: ClearWaypoints,
  SetMBSMControllerParams: SetMBSMControllerParams,
  SwitchToAutomatic: SwitchToAutomatic,
  SetPIDParams: SetPIDParams,
  GetSMControllerParams: GetSMControllerParams,
  Hold: Hold,
  ResetController: ResetController,
  StartTrajectory: StartTrajectory,
  GetWaypoints: GetWaypoints,
  InitWaypointSet: InitWaypointSet,
  SwitchToManual: SwitchToManual,
  InitWaypointsFromFile: InitWaypointsFromFile,
  GetMBSMControllerParams: GetMBSMControllerParams,
  GoTo: GoTo,
  GoToIncremental: GoToIncremental,
  InitRectTrajectory: InitRectTrajectory,
  GetPIDParams: GetPIDParams,
  InitCircularTrajectory: InitCircularTrajectory,
  IsRunningTrajectory: IsRunningTrajectory,
  SetSMControllerParams: SetSMControllerParams,
  InitHelicalTrajectory: InitHelicalTrajectory,
  AddWaypoint: AddWaypoint,
};
