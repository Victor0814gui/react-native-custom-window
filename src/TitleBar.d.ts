// main index.js
import { ColorSchemeName } from 'react-native';


interface TitleBarProps {
  backgroundColor: string;
  inactiveBackgroundColor: string;
  buttonBackgroundColor: string;
  buttonInactiveBackgroundColor: string;
  buttonForegroundColor: string;
  buttonHoverForegroundColor: string;
  buttonPressedForegroundColor: string;
  buttonInactiveForegroundColor: string;
  foregroundColor: string;
  inactiveForegroundColor: string;
  buttonHoverBackgroundColor: string;
  buttonPressedBackgroundColor: string;
}

export const titleBar: (props: TitleBarProps) => Promise<void>;
