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


interface ISetSize {
  width: number;
  height: number;
}


export interface IWindow {
  fullscreen: () => Promise<void>,
  setSize: ( width: number, height: number) => Promise<void>,
}

interface TitleBarProps {
  enableExtend: () => void;
  addBackButton: () => Promise<void>;
  removeBackButton: () => Promise<void>;
  disabledBackButton: () => Promise<void>;
  disableExtend: () => Promise<void>;
}

export interface IFilePicker {
  pickFile: () => Promise<string>;
}


export const window: IWindow;
export const FilePicker: IFilePicker;
export const titleBar: (props: TitleBarProps) => Promise<void> | TitleBarProps;
