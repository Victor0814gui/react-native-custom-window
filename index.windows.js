// main index.js
import { NativeModules } from 'react-native';
import { titleBar } from "./src/TitleBar"

const {
  window,
  FilePicker,
} = NativeModules;


export {
  titleBar,
  window,
  FilePicker,
}
