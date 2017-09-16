/**
 * @file
 * Immediate feedback on open questions.
 */
(function($) {
  Drupal.behaviors.elearningOpenQuestionCheck = {
    attach: function(context, settings) {
      $('.elearning-question-elearning-open-question', context).once('open-question-feedback').each(function(index, question) {
        var question_id = $(question).attr('id');
        $(question).find('input[type="submit"]').on('mousedown', function() {
          var answer = 'correct';
          $(this).parents('.entity-elearning-question').find('input[type="text"], textarea').each(function(textIndex, textInput) {
            var inputValue = $(textInput).val();
            // parse the value
            var questionSettings = settings['elearning_open_question'][question_id]['settings'];
            var correctAnswers = settings['elearning_open_question'][question_id]['values'][textIndex]['value'];

            if (questionSettings['case_sensitive'] === 0) {
              inputValue = inputValue.toLowerCase();
            }
            if (questionSettings['space_sensitive'] === 0) {
              inputValue = inputValue.replace(/ /g, '');
            }
            if (questionSettings['punctuation_sensitive'] === 0) {
              inputValue = inputValue.replace(/[^\w\s]|_/g, "").replace(/\s+/g, " ");
            }
            if (questionSettings['apostroph_sensitive'] === 0) {
              inputValue = inputValue.replace(/´/g, "'");
            }

            $.each(correctAnswers, function(i, correctAnswer){
              if (questionSettings['case_sensitive'] === 0) {
                correctAnswer = correctAnswer.toLowerCase();
              }
              if (questionSettings['space_sensitive'] === 0) {
                correctAnswer = correctAnswer.replace(/ /g, '');
              }
              if (questionSettings['punctuation_sensitive'] === 0) {
                correctAnswer = correctAnswer.replace(/[^\w\s]|_/g, "").replace(/\s+/g, " ");
              }
              if (questionSettings['apostroph_sensitive'] === 0) {
                correctAnswer = correctAnswer.replace(/´/g, "'");
              }
              correctAnswers[i] = correctAnswer;
            });
            if(questionSettings['multiple_options'] === 1){
              if($.inArray(inputValue, correctAnswers) == -1 ){
                answer = 'incorrect';
              }
            } else{
              if (inputValue != correctAnswers[0]) {
                console.log('wrong');
                answer = 'incorrect';
              }
            }
            if (inputValue === '') {
              answer = 'not-answered';
            }
          });
          Drupal.theme('elearningCheckAnswerImmediately', answer, question);
        });
      });
    }
  };
})(jQuery);
