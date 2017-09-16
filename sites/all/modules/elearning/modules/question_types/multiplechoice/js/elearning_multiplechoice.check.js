/**
 * @file
 * Saves answers to cookies and deletes them upon submit.
 */
(function ($) {
  Drupal.behaviors.elearningMultipleChoiceCheck = {
    attach: function (context, settings) {
      $('.elearning-question-elearning-multiplechoice', context).once('mc-feedback').each(function (index, question) {
        var question_id = $(question).attr('id');
        if (settings['elearning_multiplechoice'][question_id]['settings']['multiple_answers'] === 0) {
          $(question).find('input[type="radio"]').change(function () {

            var optionIndex = $(this).attr('value');
            if (settings['elearning_multiplechoice'][question_id]['values'][optionIndex]['value'] == 1) {
              answer = 'correct';
            } else {
              answer = 'incorrect';
            }
            Drupal.theme('elearningCheckAnswerImmediately', answer, question);
          });
        }
        if (settings['elearning_multiplechoice'][question_id]['settings']['multiple_answers'] === 1) {
          $(question).find('input[type="submit"]').on('mousedown', function () {
            var all_correct = settings['elearning_multiplechoice'][question_id]['settings']['all_correct'];
            var correct = 'not-answered';
            var answer = 'correct';
            var answered = false;
            if (all_correct === 1) {
              $(this).parents('.entity-elearning-question').find('input[type="checkbox"]').each(function (checkboxIndex, checkboxElement) {
                var value = $(checkboxElement).attr('value');
                var check = $(checkboxElement).is(':checked') == true ? 1 : 0;
                if (check != settings['elearning_multiplechoice'][question_id]['values'][value]['value']) {
                  answer = 'incorrect';
                }
              });
            } else {
              $(this).parents('.entity-elearning-question').find('input[type="checkbox"]').each(function (checkboxIndex, checkboxElement) {
                var value = $(checkboxElement).attr('value');
                if ($(checkboxElement).is(':checked') == true && settings['elearning_multiplechoice'][question_id]['values'][value]['value'] == 0) {
                  answer = 'incorrect';
                }

              });
              if($(this).parents('.entity-elearning-question').find('input[type="checkbox"]:checked').length == 0){
                answer = 'incorrect';
              }
            }
            Drupal.theme('elearningCheckAnswerImmediately', answer, question);
          });
        }
      });
    }
  };
})(jQuery);
