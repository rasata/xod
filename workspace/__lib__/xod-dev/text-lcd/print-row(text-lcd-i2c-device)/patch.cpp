
struct State {
};

{{ GENERATED_CODE }}

void printRow(LiquidCrystal_I2C* lcd, uint8_t rowLen, uint8_t rowIndex, XString str) {
    lcd->setCursor(0, rowIndex);
    uint8_t whitespace = rowLen;
    for (auto it = str.iterate(); it; ++it, --whitespace)
        lcd->write(*it);

    // Clear the rest of the line
    while (whitespace--)
        lcd->write(' ');
}

void evaluate(Context ctx) {
    auto t = getValue<input_DEV>(ctx);

    if (isInputDirty<input_DO>(ctx)) {
        XString str = getValue<input_VAL>(ctx);
        uint8_t row = (uint8_t) getValue<input_ROW>(ctx);
        if (row < 0 || row >= t.rows || length(str) > t.cols) {
            raiseError<output_OK>(ctx);
            return;
        }

        printRow(t.lcd, t.cols, row, str);
        emitValue<output_OK>(ctx, 1);
    }

    emitValue<output_DEVU0027>(ctx, t);
}
