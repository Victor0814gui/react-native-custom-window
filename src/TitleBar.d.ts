// main index.js
import { ColorSchemeName } from 'react-native';


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

export const titleBar: (props: TitleBarProps) => Promise<void>;
