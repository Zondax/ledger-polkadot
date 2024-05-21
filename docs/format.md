# Format Limitations

Currently, the application lacks the capability to set specific formats for different data types.
This limitation means that while the application can infer the display format for certain specialized types, it may
default to the format of the primitive type in other cases.

Here you can check a list of the available type encoding

```text
EncUnsigned,
EncSigned,
EncBool,
EncCompact,
EncString,
EncHexString,
EncAddress,
EncBalance,
EncCompactBalance,
EncVote,
EncEmptyVec,
```

## Format Inference

Consider the scenario where the application receives a single `byte = 0x80`

This byte can be represented in multiple ways:

- **As a Boolean**: It is out of range, as the valid Boolean values are `0` (false) and `1` (true).
- **As a Vote**: It could be interpreted as `yay` with a conviction of `None`.
- **As an Integer**: It should be displayed as `128`.

This example illustrates the challenge of intuitively displaying values without explicit format instructions.

## Handling Balances

The application also handles the display of amounts, particularly when setting the number of tokens for a transaction. 
The amount is displayed as a decimal number accompanied by the token symbol, enabling users to easily verify the transaction magnitude (e.g., 10 tokens vs. 100 tokens).

### Supported Types for Amounts

The application automatically detects and formats the following types as amounts. 
Using types not listed here is permitted but may result in a suboptimal user interface and user experience.

```text
Balance
BalanceOf<T>
BalanceOf<T, I>
DepositBalance
ExtendedBalance
PalletBalanceOf<T>
T::Balance
```

By using the appropriate type, the application ensures that amounts are displayed correctly, enhancing the overall usability.

## Address Formatting

In the Polkadot network, several types of accounts can be used, including `AccountId`, `Index`, `Raw`, `Address32`, and `Address20`. 
Similar to what was explained with Amount, if the app detects that the type is `AccountId32`, it will automatically perform the encoding from public key to address using the `SS58 prefix` sent as part of the short metadata. 
In these cases, displaying the address instead of the public key will feel more natural and enhance the user experience.

## Conclusion

Understanding these format limitations and the types supported for automatic formatting helps in developing applications that are both functional and user-friendly. 
It is crucial to use the correct types for amount-related data to maintain a high-quality user interface.

