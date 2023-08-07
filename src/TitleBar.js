// main index.js
import { NativeModules } from 'react-native';

const { titleBar: TitleBar } = NativeModules;


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
}){

  await TitleBar.TitlebarColor(
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
