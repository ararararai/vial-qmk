# GameSir VX2 Custom Keyboard

GameSir VX2の筐体を流用したRP2040ベースの有線片手キーボード。

## 仕様

- MCU: Raspberry Pi Pico（RP2040）
- スイッチ: Gateron Pro 2.0 Silver / Gateron Clear
- ソケット: Kailhホットスワップソケット
- ダイオード: 1N4148
- ファームウェア: Vial-QMK

## マトリクス

6行 x 7列（42スロット、実使用36キー）

| 役割 | ピン |
|------|------|
| COL0 | GP0  |
| COL1 | GP4  |
| COL2 | GP8  |
| COL3 | GP9  |
| COL4 | GP10 |
| COL5 | GP11 |
| COL6 | GP12 |
| ROW0 | GP1  |
| ROW1 | GP2  |
| ROW2 | GP3  |
| ROW3 | GP6  |
| ROW4 | GP7  |
| ROW5 | GP5  |

## キーマップ

ROW0: ESC,  NO,   F1,   F2,   F3,   F4,   F5
ROW1: `,    1,    2,    3,    4,    5,    6
ROW2: TAB,  Q,    W,    E,    R,    NO,   T
ROW3: CAPS, A,    S,    D,    F,    NO,   G
ROW4: LSFT, Z,    X,    C,    V,    NO,   B
ROW5: LCTL, Fn,   LALT, SPC,  NO,   NO,   M

## ビルド方法

make ararararai/gamesir_vx2:vial

## 作者

ararararai
