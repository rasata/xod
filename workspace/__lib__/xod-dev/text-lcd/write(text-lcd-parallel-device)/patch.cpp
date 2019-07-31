
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto t = getValue<input_DEV>(ctx);
    if (isInputDirty<input_DO>(ctx)) {
        t.lcd->write(getValue<input_CHAR>(ctx));
        emitValue<output_OK>(ctx, 1);
    }
    emitValue<output_DEVU0027>(ctx, t);
}
