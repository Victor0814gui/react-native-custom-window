// main index.js
import { NativeModules } from 'react-native';
import { titleBar } from "./src/TitleBar.ts"

const {
  fullscreen,
  FilePicker,
} = NativeModules;


export {
  titleBar,
  fullscreen,
  FilePicker,
}
