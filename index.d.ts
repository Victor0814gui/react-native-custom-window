// main index.js

interface TitlebarColor {
  background: string;
  backgroundInactive: string;
  buttonBackgroud: string;
  buttonBackgroudInative: string;
}


export interface IWindow {
  enableExtend: () => void,
  TitlebarColor: (
    background: string,
    backgroundInactive: string,
    buttonBackgroud: string,
    buttonBackgroudInative: string,
  ) => void,
  addBackButton: () => Promise<void>,
  removeBackButton: () => Promise<void>,
  disabledBackButton: () => Promise<void>,
  disableExtend: () => Promise<void>,
}

export interface IFilePicker {
  pickFile: () => Promise<string>,
}


export const fullscreen: IWindow;
export const FilePicker: IFilePicker;
