/**
 * @file
 *
 * Implements Jquery UI drag and drop functionality.
 */
(function ($) {
  Drupal.behaviors.elearning_dragndrop = {
    attach: function (context, settings) {

      $('.elearning-question-elearning-dragndrop', context).each(function (questionIndex, questionElement) {

        $(questionElement).find(".elearning-dragndrop-origin").draggable({
          revert: 'invalid'
        });

        $(questionElement).find('.elearning-dragndrop-origin-wrapper', context).droppable({
          over: function (event, ui) {
            $(this).addClass('hovering');
          },
          out: function (event, ui) {
            $(this).removeClass('hovering');
          },
          drop: function (event, ui) {
            var item = $(ui.draggable).data('position');

            $(ui.draggable).removeClass('dropped-element').css({
              top: "0px",
              left: "0px"
            });
            $(questionElement).find('input[type="text"]').each(function (inputIndex, inputElement) {

              if (parseInt(this.value) === parseInt(item)) {

                $(inputElement).val('');
                $(questionElement).find('.elearning-dragndrop-destination').eq(inputIndex).removeClass('dropped');
              } else if(this.value === ''){
                $(questionElement).find('.elearning-dragndrop-destination').eq(inputIndex).removeClass('dropped');
              } else{
                //$(questionElement).find('.elearning-dragndrop-destination').eq(inputIndex).removeClass('dropped');
              }
            });
            $(questionElement).find('.elearning-dragndrop-origin-wrapper').removeClass('empty');

            $(this).removeClass('hovering');
          }
        });


        $(questionElement).find('.elearning-dragndrop-destination', context).droppable({
          over: function (event, ui) {
            $(this).addClass('hovering');
          },
          out: function (event, ui) {
            $(this).removeClass('hovering');
          },
          drop: function (event, ui) {
            var destination_index = $(this).parents('.entity-elearning-question').find('.elearning-dragndrop-destination').index(this);
            var item = $(ui.draggable).data('position');

            $(ui.draggable).addClass('dropped-element');

            var occupierItem = $(questionElement).find('input').eq(destination_index).val();
            if (occupierItem !== item) {
              $(questionElement).find('.elearning-dragndrop-origin[data-position="'+occupierItem+'"]').removeClass('dropped-element').css({
                top: 0,
                left: 0,
              });
            }

            $(questionElement).find('input').each(function (inputIndex, inputValue) {
              if ($(inputValue).val() == item) {
                $(inputValue).val('');
                $(questionElement).find('.elearning-dragndrop-destination').eq(inputIndex).removeClass('dropped');
              }
            });

            if ($(questionElement).find('.elearning-dragndrop-origin:not(.dropped-element)').length === 0) {
              $(questionElement).find('.elearning-dragndrop-origin-wrapper').addClass('empty');
            } else {
              $(questionElement).find('.elearning-dragndrop-origin-wrapper').removeClass('empty');
            }

            $(questionElement).find('.form-type-textfield').eq(destination_index).find('input').val(item);

            $(questionElement).find('.elearning-dragndrop-destination').eq(destination_index).addClass('dropped');

            $(ui.draggable).css({
              top: 0,
              left: 0,
            }).css({
              top: $(this).offset().top + $(this).height() / 2 - $(ui.draggable).offset().top - $(ui.draggable).height() / 2,
              left: $(this).offset().left + $(this).width() / 2 - $(ui.draggable).offset().left - $(ui.draggable).width() / 2,
            });
            $(this).removeClass('hovering');
          },
        });
      });
    }
  };
})(jQuery);
