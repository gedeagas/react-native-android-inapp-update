[@bs.module "react-native"]
[@bs.scope ("NativeModules", "AndroidInappUpdates")]
external checkAppUpdate: (~appUpdateType: string) => _ = "checkAppUpdate";

[@bs.module "react-native"]
[@bs.scope ("NativeModules", "AndroidInappUpdates")]
external checkAppUpdateWithStaleness:
  (~appUpdateType: string, ~clientVersionStalenessDays: int) => _ =
  "checkAppUpdateWithStaleness";

let updateFlowDict = Js.Dict.fromList([("IMMEDIATE", 1), ("FLEXIBLE", 0)]);

let startUpdateFlow =
    (~appUpdateType: string, ~clientVersionStalenessDays: int=0): _ => {
  let updateCode =
    switch (
      Js.Dict.get(updateFlowDict, String.uppercase_ascii(appUpdateType))
    ) {
    | Some(value) => value
    | None => 1
    };
  checkAppUpdate(updateCode, clientVersionStalenessDays);
};
