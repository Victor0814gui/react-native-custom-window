// main index.js
import { NativeModules } from 'react-native';


interface TitleBarProps {
  backgroundColor: string;
  inactiveBackgroundColor?: string;
  buttonBackgroundColor?: string;
  buttonInactiveBackgroundColor?: string;
  buttonForegroundColor?: string;
  buttonHoverForegroundColor?: string;
  buttonPressedForegroundColor?: string;
  buttonInactiveForegroundColor?: string;
  foregroundColor?: string;
  inactiveForegroundColor?: string;
  buttonHoverBackgroundColor?: string;
  buttonPressedBackgroundColor?: string;
}

interface NativeModulesProps {
  TitlebarColor: (
    backgroundColor: string,
    inactiveBackgroundColor: string,
    buttonBackgroundColor: string,
    buttonInactiveBackgroundColor: string,
    buttonForegroundColor: string,
    buttonHoverForegroundColor: string,
    buttonPressedForegroundColor: string,
    buttonInactiveForegroundColor: string,
    foregroundColor: string,
    inactiveForegroundColor: string,
    buttonHoverBackgroundColor: string,
    buttonPressedBackgroundColor: string,
  ) => Promise<void>;
}

const { TitlebarColor: TitleBar } = NativeModules as NativeModulesProps;


async function titleBar({
  backgroundColor = "#f2f2f2",
  inactiveBackgroundColor = "#f2f2f2",
  buttonBackgroundColor = "#f2f2f2",
  buttonInactiveBackgroundColor = "#f2f2f2",
  buttonForegroundColor = "#f2f2f2",
  buttonHoverForegroundColor = "#f2f2f2",
  buttonPressedForegroundColor = "#f2f2f2",
  buttonInactiveForegroundColor = "#f2f2f2",
  foregroundColor = "#f2f2f2",
  inactiveForegroundColor = "#f2f2f2",
  buttonHoverBackgroundColor = "#f2f2f2",
  buttonPressedBackgroundColor = "#f2f2f2",
}: TitleBarProps){

  await TitleBar(
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
  );
}


export {
  titleBar,
}
