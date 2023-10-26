from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.scrollview import ScrollView

from kivy.uix.boxlayout import BoxLayout
from kivy.uix.gridlayout import GridLayout

from kivy.config import Config
Config.set('graphics', 'resizable', 0)
Config.set('graphics', 'width', 400)
Config.set('graphics', 'height', 500)

class MainApp(App):
	font_size = 75
	
	def add_simvol(self, instance):
		text = self.label.text
		if len(text) <= 25:
			text = text + instance.text
			self.label.text = text
		
	def check_char(self, instance):
		text = self.label.text
		if text != "":
			if len(text) <= 25:
				if text[-1] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
					self.label.text = self.label.text + instance.text
	
	def return_result(self, instance):
		if self.label.text != "":
			try:
				text = self.label.text
				if "×" in text:
					text = text.replace("×", "*")
				if "÷" in text:
					text = text.replace("÷", "/")
				if "^" in text:
					text = text.replace("^", "**")
				if "√" in text:
					text = text.replace("√", "**(1/2)")
					
				text = eval(text)
				self.label.text = str(text)
			except Exception:
				pass
				self.label.text = "Error"
		
	def clean(self, instance):
		self.label.text = ""
		
	def del_last_simvol(self, instance):
		text = self.label.text
		self.label.text = text[:-1]
	
	def build(self):
		
		main = BoxLayout(orientation = 'vertical')
		
		######Control##########
		control = GridLayout(cols = 4, 
		size_hint = [1, .2])
		
		control.add_widget(Button(text = "C", 
		font_size = self.font_size,
		on_press = self.clean))
		
		control.add_widget(Button(text = "<×", 
		font_size = self.font_size,
		on_press = self.del_last_simvol))
		
		control.add_widget(Button(text = "√", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		control.add_widget(Button(text = "^", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		
		panel = BoxLayout(orientation = 'horizontal')
		
		####Keyboard#########
		keyboard = GridLayout(cols = 3, size_hint = [.6, 1],)
		
		keyboard.add_widget(Button(
		text = "7", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "8", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "9", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "4", 
		font_size = self.font_size,
		on_press = self.add_simvol))	
			
		keyboard.add_widget(Button(
		text = "5", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "6", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		
		keyboard.add_widget(Button(
		text = "1", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "2",
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "3", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = ".", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		keyboard.add_widget(Button(
		text = "0", 
		font_size = self.font_size,
		on_press = self.add_simvol
		))
		
		keyboard.add_widget(Button(
		text = "=", 
		font_size = self.font_size,
		on_press = self.return_result))
		
		#####Math operation######
		math = GridLayout(cols = 1, size_hint = [.2, 1],)
		
		math.add_widget(Button(
		text = "÷", 
		font_size = self.font_size,
		on_press = self.check_char
		))
		
		math.add_widget(Button(
		text = "×", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		math.add_widget(Button(
		text = "-", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		math.add_widget(Button(
		text = "+", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		panel.add_widget(keyboard)
		panel.add_widget(math)
		
		display = ScrollView(size_hint_y = .3, do_scroll = True)
		self.label = Label(text = "", 
		font_size = 70,
		size_hint_y = 1)
		
		display.add_widget(self.label)
		
		main.add_widget(display)
		main.add_widget(control)
		main.add_widget(panel)
		return main
		
if __name__ == '__main__':
	MainApp().run()
  
