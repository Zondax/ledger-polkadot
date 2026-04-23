module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  transformIgnorePatterns: ['node_modules/(?!(get-port)/)'],
  transform: {
    '^.+\\.[jt]sx?$': 'ts-jest',
  },
  reporters: ['default', ['summary', { summaryThreshold: 1 }]],
  globalSetup: './globalsetup.js',
}
