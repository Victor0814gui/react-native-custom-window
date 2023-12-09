// main index.js
import { TurboModuleRegistry } from 'react-native';

const window = TurboModuleRegistry.get('window');
const titleBar = TurboModuleRegistry.get('titleBar');
const FilePicker = TurboModuleRegistry.get('FilePicker');

export {
  titleBar,
  window,
  FilePicker,
}
