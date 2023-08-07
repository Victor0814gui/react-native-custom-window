// main index.js

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



export interface IWindow {
  enableExtend: () => void,
  TitlebarColor: (props: TitleBarProps) => void,
  addBackButton: () => Promise<void>,
  removeBackButton: () => Promise<void>,
  disabledBackButton: () => Promise<void>,
  disableExtend: () => Promise<void>,
}

interface TitleBarProps {
  enableExtend: () => void;
  TitlebarColor: (props: TitleBarProps) => void;
  addBackButton: () => Promise<void>;
  removeBackButton: () => Promise<void>;
  disabledBackButton: () => Promise<void>;
  disableExtend: () => Promise<void>;
}

export interface IFilePicker {
  pickFile: () => Promise<string>;
}


export const fullscreen: IWindow;
export const FilePicker: IFilePicker;
export const titleBar: (props: TitleBarProps) => Promise<void> | TitleBarProps;
