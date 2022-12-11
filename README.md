# This is still a WIP

# This is a simple headeronly library for handling file sizes in a human readable way.

First I want to give credits to [neosmart/prettysize-rs](https://github.com/neosmart/prettysize-rs) for the idea.

## Tiny precision specificities
The `{fmt}` precision behavior was changed: 
- it now gives the number of decimal places instead of the number of significant digits.
- `Bytes` numbers never have a decimal point (as they are integers) => can be disabled by defining `SIZE_KEEP_BYTES_DECIMALS` before including the header.
The rest of the behavior is the same as the original `{fmt}` library.
