// main index.js
import { fullscreen,IWindow } from "./src/Window"
import { NativeModules } from 'react-native';


const {
  fullscreen,
  FilePicker
} = NativeModules;


export {
  fullscreen,
  FilePicker,
}
