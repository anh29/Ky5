
// Doi tuong Validator
function Validator(options) {

  function getParent(element, selector) {
    while (element.parentElement) {
      // Ktra parentElement co chua selector tuong ung ko
      if (element.parentElement.matches(selector)) {
        return element.parentElement
      }
      element = element.parentElement
    }
  }

  var selectorRules = {}

  // Ham thuc hien validate
  function validate(inputElement, rule) {
    var errorElement =
      getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector);
    var errorMessage;

    // Lay ra cac rules cua selector
    var rules = selectorRules[rule.selector]

    // Lap qua tung rule va kiem tra
    // Neu co loi -> dung
    for (var i = 0; i < rules.length; ++i) {

      switch (inputElement.type) {
        case 'radio':
        case 'checkbox':
          errorMessage = rules[i](
            formElement.querySelector(rule.selector + ':checked')
          )
          break;
        default:
          errorMessage = rules[i](inputElement.value)
      }
      if (errorMessage) break;
    }

    if (errorMessage) {
      errorElement.innerText = errorMessage;
      getParent(inputElement, options.formGroupSelector).classList.add("invalid");
    } else {
      errorElement.innerText = "";
      getParent(inputElement, options.formGroupSelector).classList.remove("invalid");
    }

    return !errorMessage;
  }

  // Lay element cua form can validate
  var formElement = document.querySelector(options.form);

  if (formElement) {
    // Khi submit form
    formElement.onsubmit = function (e) {
      e.preventDefault();

      var isFormValid = true

      // Lap qua tung rules va validate
      options.rules.forEach(function (rule) {
        var inputElement = formElement.querySelector(rule.selector);
        var isValid = validate(inputElement, rule)
        
        if (!isValid) {
          isFormValid = false
        }
      })

      // Xu ly khi ko co loi
      if (isFormValid) {
        // TH submit voi js
        if (typeof options.onSubmit === 'function') {

          var enableInputs = formElement.querySelectorAll("[name]"); // lấy tất cả field có attribute là name
          var formValues = Array.from(enableInputs).reduce(function (
            values,
            input
          ) {
            switch (input.type) {
              case 'checkbox':
                if (!input.matches(":checked")) {
                  values[input.name] = ''
                  return values
                }

                if (!Array.isArray(values[input.name])) {
                  values[input.name] = []
                }

                values[input.name].push(input.value)

                break
              case 'radio':
                if (input.matches(':checked')) {
                  values[input.name] = input.value
                }
                break
              case 'file':
                values[input.name] = input.files
                break
              default:
                values[input.name] = input.value;
            }
              
            return values;
          },
          {});
          options.onSubmit(formValues)
        }
        // TH submit voi hah vi mac dinh
        else {
          formElement.submit()
        }
      }
    }

    // Lap qua moi rule va xu ly (lang nghe su kien blur, input ...)
    options.rules.forEach(function (rule) {

      // Luu lai rules cho moi input
      if (Array.isArray(selectorRules[rule.selector])) {
        selectorRules[rule.selector].push(rule.test)
      } else {
        selectorRules[rule.selector] = [rule.test];
      }

      var inputElement = formElement.querySelector(rule.selector);

      if (inputElement) {
        // Xu ly truong hop blur khoi input
        inputElement.onblur = function () {
          validate(inputElement, rule)
        }

        // Xu ly khi user nhap vao input
        inputElement.oninput = function () {
          var errorElement =
            getParent(inputElement, options.formGroupSelector).querySelector(options.errorSelector);
          errorElement.innerText = "";
          getParent(inputElement, options.formGroupSelector).classList.remove("invalid");
        }
      }
    });
  }
}

// Định nghĩa rules
// Nguyên tắc của các rules:
// 1. Khi có lỗi => return message lỗi
// 2. Khi ko có lỗi => ko trả gì cả (undefined)
Validator.isRequired = function (selector, message) {
  return {
    selector: selector,
    test: function (value) {
      return value ? undefined : message || "Vui long nhap truong nay.";
    }
  }
}

Validator.isEmail = function (selector, message) {
  return {
    selector: selector,
    test: function (value) {
      var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/
      return regex.test(value)
        ? undefined
        : message || "Vui long nhap email hop le.";
    }
  };
};

Validator.minLength = function (selector, min, message) {
  return {
    selector: selector,
    test: function (value) {
      return value.length >= min
        ? undefined
        : message || `Vui long nhap toi thieu ${min} ky tu.`;
    }
  }
}

Validator.isConfirmed = function (selector, getConfirmValue, message) {
  return {
    selector: selector,
    test: function (value) {
      return value === getConfirmValue() ? undefined : message || 'Gia tri nhap vao khong chinh xac.'
    }
  }
}