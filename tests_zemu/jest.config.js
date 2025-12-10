module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  transformIgnorePatterns: ['^.+\\.js$'],
  reporters: ['default', ['summary', { summaryThreshold: 1 }]],
  globalSetup: './globalsetup.js',
  // Retry flaky tests up to 2 times (3 attempts total)
  retryTimes: 2,
}
