// main index.js
import { ColorSchemeName, NativeModules } from 'react-native';


interface TitleBarProps {
  backgroundColor: ColorSchemeName;
  inactiveBackgroundColor: ColorSchemeName;
  buttonBackgroundColor: ColorSchemeName;
  buttonInactiveBackgroundColor: ColorSchemeName;
  buttonForegroundColor: ColorSchemeName;
  buttonHoverForegroundColor: ColorSchemeName;
  buttonPressedForegroundColor: ColorSchemeName;
  buttonInactiveForegroundColor: ColorSchemeName;
  foregroundColor: ColorSchemeName;
  inactiveForegroundColor: ColorSchemeName;
  buttonHoverBackgroundColor: ColorSchemeName;
  buttonPressedBackgroundColor: ColorSchemeName;
}

interface NativeModulesProps {
  titleBar: (
    backgroundColor: ColorSchemeName,
    inactiveBackgroundColor: ColorSchemeName,
    buttonBackgroundColor: ColorSchemeName,
    buttonInactiveBackgroundColor: ColorSchemeName,
    buttonForegroundColor: ColorSchemeName,
    buttonHoverForegroundColor: ColorSchemeName,
    buttonPressedForegroundColor: ColorSchemeName,
    buttonInactiveForegroundColor: ColorSchemeName,
    foregroundColor: ColorSchemeName,
    inactiveForegroundColor: ColorSchemeName,
    buttonHoverBackgroundColor: ColorSchemeName,
    buttonPressedBackgroundColor: ColorSchemeName,
  ) => Promise<void>;
}

const { titleBar: TitleBar } = NativeModules as NativeModulesProps;


function titleBar({
  backgroundColor,
  inactiveBackgroundColor,
  buttonBackgroundColor,
  buttonInactiveBackgroundColor,
  buttonForegroundColor,
  buttonHoverForegroundColor,
  buttonPressedForegroundColor,
  buttonInactiveForegroundColor,
  foregroundColor,
  inactiveForegroundColor,
  buttonHoverBackgroundColor,
  buttonPressedBackgroundColor,
}: TitleBarProps){

  TitleBar(
    backgroundColor,
    inactiveBackgroundColor,
    buttonBackgroundColor,
    buttonInactiveBackgroundColor,
    buttonForegroundColor,
    buttonHoverForegroundColor,
    buttonPressedForegroundColor,
    buttonInactiveForegroundColor,
    foregroundColor,
    inactiveForegroundColor,
    buttonHoverBackgroundColor,
    buttonPressedBackgroundColor,
  )
}


export {
  titleBar,
}
