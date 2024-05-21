module.exports = {
  languageOptions: {
    ecmaVersion: 'latest',
    sourceType: 'module',
    globals: {
      window: 'readonly',
      document: 'readonly',
      process: 'readonly',
      require: 'readonly',
    },
    parserOptions: {
      project: 'tsconfig.json',
    },
  },
  ignores: ['dist/*', 'node_modules/*'],
  plugins: {
    'unused-imports': require('eslint-plugin-unused-imports'),
    '@typescript-eslint': require('@typescript-eslint/eslint-plugin'),
    'eslint-plugin-tsdoc': require('eslint-plugin-tsdoc'),
    promise: require('eslint-plugin-promise'),
  },
  rules: {
    curly: 'warn',
    'prefer-const': 'warn',
    'no-else-return': 'warn',
    complexity: ['warn', 1000],
    'no-unneeded-ternary': 'warn',
    'no-alert': 'warn',
    'no-empty': 'warn',
    'no-useless-catch': 'error',
    'require-await': 'warn',
    'no-continue': 'warn',
    'promise/prefer-await-to-then': 'warn',
    'no-console': 'warn',
    'unused-imports/no-unused-imports': 'warn',
    'no-magic-numbers': 'off',
  },
}
