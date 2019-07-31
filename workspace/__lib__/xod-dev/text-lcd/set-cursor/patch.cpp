
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    if (isInputDirty<input_DO>(ctx)) {
        auto lcd = getValue<input_DEV>(ctx);
        // TODO: Raise an error if POS/ROW is out of the range?
        lcd->setCursor(getValue<input_POS>(ctx), getValue<input_ROW>(ctx));
        emitValue<output_OK>(ctx, 1);
    }

    emitValue<output_DEVU0027>(ctx, lcd);
}
