function Validator(formSelector) {
  var _this = this;
  var formRules = {};

  function getParent(element, selector) {
    while (element.parentElement) {
      if (element.parentElement.matches(selector)) {
        return element.parentElement;
      }
      element = element.parentElement;
    }
  }

  /**
   * Quy uoc tao rules:
   * - Neu co loi -> return 'error message'
   * - Neu ko co loi -> return 'undefined'
   */
  var validatorRules = {
    required: function (value) {
      return value ? undefined : "Vui long nhap truong nay.";
    },
    email: function (value) {
      var regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/; //biểu thức chính quy
      return regex.test(value) ? undefined : "Vui long nhap email hop le.";
    },
    min: function (min) {
      return function (value) {
        return value.length >= min
          ? undefined
          : `Vui long nhap it nhat ${min} ky tu.`;
      };
    },
    max: function (max) {
      return function (value) {
        return value.length <= max
          ? undefined
          : `Vui long nhap toi da ${max} ky tu.`;
      };
    },
  };
  // Lay ra form element trong DOM theo 'formSelector'
  var formElement = document.querySelector(formSelector);

  // Xu ly khi co element trong DOM
  if (formElement) {
    var inputs = formElement.querySelectorAll("[name][rules]");

    for (var input of inputs) {
      var rules = input.getAttribute("rules").split("|");
      for (var rule of rules) {
        var ruleInfo;
        var isRuleHasValue = rule.includes(":");

        if (isRuleHasValue) {
          ruleInfo = rule.split(":");
          rule = ruleInfo[0];
        }

        var ruleFunc = validatorRules[rule];

        if (isRuleHasValue) {
          ruleFunc = ruleFunc(ruleInfo[1]);
        }

        if (Array.isArray(formRules[input.name])) {
          formRules[input.name].push(ruleFunc);
        } else {
          formRules[input.name] = [ruleFunc];
        }
      }

      // Lang nghe su kien de validate (blur, change...)
      input.onblur = handleValidate;
      input.oninput = handleClearError;
    }
    function handleValidate(event) {
      var rules = formRules[event.target.name]; // Lay rules (dang func) cua tung key (target.name)
      var errorMessage;

      for (var rule of rules) {
        errorMessage = rule(event.target.value);
        if (errorMessage) break;
      }

      // Neu co loi thi hien thi message loi
      if (errorMessage) {
        var formGroup = getParent(event.target, ".form-group");
        if (formGroup) {
          formGroup.classList.add("invalid");
          var formMessage = formGroup.querySelector(".form-message");
          if (formMessage) {
            formMessage.innerText = errorMessage;
          }
        }
      }

      return !errorMessage;
    }

    // Ham clear message loi
    function handleClearError(event) {
      var formGroup = getParent(event.target, ".form-group");
      if (formGroup.classList.contains("invalid")) {
        formGroup.classList.remove("invalid");
        var formMessage = formGroup.querySelector(".form-message");

        if (formMessage) {
          formMessage.innerText = "";
        }
      }
    }
  }

  // Xu ly hanh vi submit form
  formElement.onsubmit = function (event) {
    event.preventDefault();

    var inputs = formElement.querySelectorAll("[name][rules]");
    var isValid = true;

    for (var input of inputs) {
      if (!handleValidate({ target: input })) {
        isValid = false;
      }
    }

    // Khi ko co loi thi submit form
    if (isValid) {
      if (typeof _this.onSubmit === "function") {
        var enableInputs = formElement.querySelectorAll("[name]"); // lấy tất cả field có attribute là name
        var formValues = Array.from(enableInputs).reduce(function (
          values,
          input
        ) {
          switch (input.type) {
            case "checkbox":
              if (!input.matches(":checked")) {
                values[input.name] = "";
                return values;
              }

              if (!Array.isArray(values[input.name])) {
                values[input.name] = [];
              }

              values[input.name].push(input.value);

              break;
            case "radio":
              if (input.matches(":checked")) {
                values[input.name] = input.value;
              }
              break;
            case "file":
              values[input.name] = input.files;
              break;
            default:
              values[input.name] = input.value;
          }

          return values;
        },
        {});

        // Goi ham onSubmit va tra ve gia tri cua form
        _this.onSubmit(formValues);
      } else {
        formElement.submit();
      }
    }
  };
}
