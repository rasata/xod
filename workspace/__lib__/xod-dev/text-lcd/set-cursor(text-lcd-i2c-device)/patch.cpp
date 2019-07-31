
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto t = getValue<input_DEV>(ctx);

    if (isInputDirty<input_DO>(ctx)) {
        uint8_t pos = (uint8_t) getValue<input_POS>(ctx);
        uint8_t row = (uint8_t) getValue<input_ROW>(ctx);

        // Check that `POS` and `ROW` is in the possible range of the LCD
        if (pos < 0 || pos > t.cols || row < 0 || row > t.rows) {
            raiseError<output_OK>(ctx);
            return;
        }

        t.lcd->setCursor(getValue<input_POS>(ctx), getValue<input_ROW>(ctx));
        emitValue<output_OK>(ctx, 1);
    }

    emitValue<output_DEVU0027>(ctx, t);
}
