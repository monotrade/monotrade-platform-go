// var addon = require('../native');

// console.log(addon.hello());


// exports.testDemo = function() {
//     console.log("this is test demo!!!!!!");
// };

const ffi = require('ffi-napi');
/**
 * 先定义一个函数, 用来在窗口中显示字符
 * @param {String} text
 * @return {*} none
 */
function showText(text) {
  return new Buffer(text, 'ucs2').toString('binary');
};
// 通过ffi加载user32.dll
// const myUser32 = new ffi.Library('user32', {
//   'MessageBoxW': // 声明这个dll中的一个函数
//     [
//       'int32', ['int32', 'string', 'string', 'int32'], // 用json的格式罗列其返回类型和参数类型
//     ],
// });

// 通过ffi加载myAddDll.dll
const myAddDll = new ffi.Library('../native/export', {
  'funAdd': // 声明这个dll中的一个函数
    [
      'int', ['int', 'int'], // 用json的格式罗列其返回类型和参数类型
    ],
  'selectball': ['void', ['pointer']],
});

var callback = ffi.Callback('void', ['int', 'string'],
      function (id, name) {
        console.log("id: ", id);
        console.log("name: ", name);
      });
    myHelloLib.selectball(callback);
