import pygame, sys, time
from settings import *
 
 
class Game:
    def __init__(self):
        
        # general setup
        pygame.init()
        self.display_surface = pygame.display.set_mode((WINDOW_WIDTH,WINDOW_HEIGHT))
        pygame.display.set_caption('Breakout')
 
    def run(self):
        last_time = time.time()
        while True:
            
            # delta time
            dt = time.time() - last_time
            last_time = time.time()
 
            # event loop
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
 
            # update window
            pygame.display.update()
 
if __name__ == '__main__':
    game = Game()
    game.run()

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720

BLOCK_MAP = [
	'666666666666',
	'444557755444',
	'333333333333',
	'222222222222',
	'111111111111',
	'            ',
	'            ',
	'            ',
	'            ']

COLOR_LEGEND = {
	'1': 'blue',
	'2': 'green',
	'3': 'red',
	'4': 'orange',
	'5': 'purple',
	'6': 'bronce',
	'7': 'grey',
}

GAP_SIZE = 2
BLOCK_HEIGHT = WINDOW_HEIGHT / len(BLOCK_MAP) - GAP_SIZE
BLOCK_WIDTH = WINDOW_WIDTH / len(BLOCK_MAP[0]) - GAP_SIZE
TOP_OFFSET = WINDOW_HEIGHT // 30

UPGRADES = ['speed','laser','heart','size']
class Upgrade(pygame.sprite.Sprite):
	def __init__(self,pos,upgrade_type,groups):
		super().__init__(groups)
		self.upgrade_type = upgrade_type
		self.image = pygame.image.load(f'../graphics/upgrades/{upgrade_type}.png').convert_alpha()
		self.rect = self.image.get_rect(midtop = pos)

		self.pos = pygame.math.Vector2(self.rect.topleft)
		self.speed = 300

	def update(self,dt):
		self.pos.y += self.speed * dt
		self.rect.y = round(self.pos.y)

		if self.rect.top > WINDOW_HEIGHT + 100:
			self.kill()

class Projectile(pygame.sprite.Sprite):
	def __init__(self,pos,surface,groups):
		super().__init__(groups)
		self.image = surface
		self.rect = self.image.get_rect(midbottom = pos)

		self.pos = pygame.math.Vector2(self.rect.topleft)
		self.speed = 300

	def update(self,dt):
		self.pos.y -= self.speed * dt
		self.rect.y = round(self.pos.y)

		if self.rect.bottom <= -100:
			self.kill()

class Player(pygame.sprite.Sprite):
	def __init__(self,groups,surfacemaker):
		super().__init__(groups)

		# setup
		self.display_surface = pygame.display.get_surface()
		self.surfacemaker = surfacemaker
		self.image = surfacemaker.get_surf('player',(WINDOW_WIDTH // 10,WINDOW_HEIGHT // 20))

		# position
		self.rect = self.image.get_rect(midbottom = (WINDOW_WIDTH // 2,WINDOW_HEIGHT - 20))
		self.old_rect = self.rect.copy()
		self.direction = pygame.math.Vector2()
		self.pos = pygame.math.Vector2(self.rect.topleft)
		self.speed = 300

		self.hearts = 3

		# laser
		self.laser_amount = 2
		self.laser_surf = pygame.image.load('../graphics/other/laser.png').convert_alpha()
		self.laser_rects = []

	def input(self):
		keys = pygame.key.get_pressed()
		if keys[pygame.K_RIGHT]:
			self.direction.x = 1
		elif keys[pygame.K_LEFT]:
			self.direction.x = -1
		else:
			self.direction.x = 0

	def screen_constraint(self):
		if self.rect.right > WINDOW_WIDTH:
			self.rect.right = WINDOW_WIDTH
			self.pos.x = self.rect.x
		if self.rect.left < 0:
			self.rect.left = 0
			self.pos.x = self.rect.x

	def upgrade(self,upgrade_type):
		if upgrade_type == 'speed':
			self.speed += 50
		if upgrade_type == 'heart':
			self.hearts += 1

		if upgrade_type == 'size':
			new_width = self.rect.width * 1.1
			self.image = self.surfacemaker.get_surf('player',(new_width,self.rect.height))
			self.rect = self.image.get_rect(center = self.rect.center)
			self.pos.x = self.rect.x

		if upgrade_type == 'laser':
			self.laser_amount += 1

	def display_lasers(self):
		self.laser_rects = []
		if self.laser_amount > 0:
			divider_length = self.rect.width / (self.laser_amount + 1)
			for i in range(self.laser_amount):
				x = self.rect.left + divider_length * (i + 1)
				laser_rect = self.laser_surf.get_rect(midbottom = (x,self.rect.top))
				self.laser_rects.append(laser_rect)

			for laser_rect in self.laser_rects:
				self.display_surface.blit(self.laser_surf,laser_rect)

	def update(self,dt):
		self.old_rect = self.rect.copy()
		self.input()
		self.pos.x += self.direction.x * self.speed * dt
		self.rect.x = round(self.pos.x) 
		self.screen_constraint()
		self.display_lasers()

class Ball(pygame.sprite.Sprite):
	def __init__(self,groups,player,blocks):
		super().__init__(groups)

		# collision objects
		self.player = player
		self.blocks = blocks

		# graphics setup
		self.image = pygame.image.load('../graphics/other/ball.png').convert_alpha()

		# position setup
		self.rect = self.image.get_rect(midbottom = player.rect.midtop)
		self.old_rect = self.rect.copy()
		self.pos = pygame.math.Vector2(self.rect.topleft)
		self.direction = pygame.math.Vector2((choice((1,-1)),-1))
		self.speed = 400

		# active
		self.active = False

		# sounds

		self.impact_sound = pygame.mixer.Sound('../sounds/impact.wav')
		self.impact_sound.set_volume(0.1)

		self.fail_sound = pygame.mixer.Sound('../sounds/fail.wav')
		self.fail_sound.set_volume(0.1)

	def window_collision(self,direction):
		if direction == 'horizontal':
			if self.rect.left < 0:
				self.rect.left = 0
				self.pos.x = self.rect.x
				self.direction.x *= -1

			if self.rect.right > WINDOW_WIDTH:
				self.rect.right = WINDOW_WIDTH
				self.pos.x = self.rect.x
				self.direction.x *= -1

		if direction == 'vertical':
			if self.rect.top < 0:
				self.rect.top = 0
				self.pos.y = self.rect.y
				self.direction.y *= -1

			if self.rect.bottom > WINDOW_HEIGHT:
				self.active = False
				self.direction.y = -1
				self.player.hearts -= 1
				self.fail_sound.play()
				
	def collision(self,direction):
		# find overlapping objects 
		overlap_sprites = pygame.sprite.spritecollide(self,self.blocks,False)
		if self.rect.colliderect(self.player.rect):
			overlap_sprites.append(self.player)

		if overlap_sprites:
			if direction == 'horizontal':
				for sprite in overlap_sprites:
					if self.rect.right >= sprite.rect.left and self.old_rect.right <= sprite.old_rect.left:
						self.rect.right = sprite.rect.left - 1
						self.pos.x = self.rect.x
						self.direction.x *= -1
						self.impact_sound.play()

					if self.rect.left <= sprite.rect.right and self.old_rect.left >= sprite.old_rect.right:
						self.rect.left = sprite.rect.right + 1
						self.pos.x = self.rect.x
						self.direction.x *= -1
						self.impact_sound.play()

					if getattr(sprite,'health',None):
						sprite.get_damage(1)


			if direction == 'vertical':
				for sprite in overlap_sprites:
					if self.rect.bottom >= sprite.rect.top and self.old_rect.bottom <= sprite.old_rect.top:
						self.rect.bottom = sprite.rect.top - 1
						self.pos.y = self.rect.y
						self.direction.y *= -1
						self.impact_sound.play()

					if self.rect.top <= sprite.rect.bottom and self.old_rect.top >= sprite.old_rect.bottom:
						self.rect.top = sprite.rect.bottom + 1
						self.pos.y = self.rect.y
						self.direction.y *= -1
						self.impact_sound.play()

					if getattr(sprite,'health',None):
						sprite.get_damage(1)

	def update(self,dt):
		if self.active:

			if self.direction.magnitude() != 0:
				self.direction = self.direction.normalize()

			# create old rect
			self.old_rect = self.rect.copy()

			# horizontal movement + collision
			self.pos.x += self.direction.x * self.speed * dt
			self.rect.x = round(self.pos.x)
			self.collision('horizontal')
			self.window_collision('horizontal')

			# vertical movement + collision
			self.pos.y += self.direction.y * self.speed * dt
			self.rect.y= round(self.pos.y)
			self.collision('vertical')
			self.window_collision('vertical')
		else:
			self.rect.midbottom = self.player.rect.midtop
			self.pos = pygame.math.Vector2(self.rect.topleft)

class Block(pygame.sprite.Sprite):
	def __init__(self,block_type,pos,groups,surfacemaker,create_upgrade):
		super().__init__(groups)
		self.surfacemaker = surfacemaker
		self.image = self.surfacemaker.get_surf(COLOR_LEGEND[block_type],(BLOCK_WIDTH, BLOCK_HEIGHT))
		self.rect = self.image.get_rect(topleft = pos)
		self.old_rect = self.rect.copy()

		# damage information
		self.health = int(block_type)

		# upgrade
		self.create_upgrade = create_upgrade

	def get_damage(self,amount):
		self.health -= amount

		if self.health > 0:
			self.image = self.surfacemaker.get_surf(COLOR_LEGEND[str(self.health)],(BLOCK_WIDTH, BLOCK_HEIGHT))
		else:
			if randint(0,10) < 9:
				self.create_upgrade(self.rect.center)
			self.kill()

class SurfaceMaker:
	def __init__(self):
		# import all the graphics
		for index, info in enumerate(walk('../graphics/blocks')):
			if index == 0:
				self.assets = {color:{} for color in info[1]}
			else:
				for image_name in info[2]:
					color_type = list(self.assets.keys())[index - 1]
					full_path = '../graphics/blocks' + f'/{color_type}/' + image_name
					surf = pygame.image.load(full_path).convert_alpha()
					self.assets[color_type][image_name.split('.')[0]] = surf

	def get_surf(self,block_type,size):
		
		# create one surface with the graphics with any size
		image = pygame.Surface(size)
		image.set_colorkey((0,0,0))
		sides = self.assets[block_type]
		
		# 4 corners
		image.blit(sides['topleft'],(0,0))
		image.blit(sides['topright'],(size[0] - sides['topright'].get_width(),0))
		image.blit(sides['bottomleft'],(0,size[1] - sides['bottomleft'].get_height()))
		image.blit(sides['bottomright'],(size[0] - sides['bottomright'].get_width(),size[1] - sides['bottomleft'].get_height()))

		# top side 
		top_width = size[0] - (sides['topleft'].get_width() + sides['topright'].get_width())
		scaled_top_surf = pygame.transform.scale(sides['top'],(top_width,sides['top'].get_height()))
		image.blit(scaled_top_surf,(sides['topleft'].get_width(),0))

		# left side
		left_height = size[1] - (sides['topleft'].get_height() + sides['bottomleft'].get_height())
		scaled_left_surf = pygame.transform.scale(sides['left'],(sides['left'].get_width(),left_height))
		image.blit(scaled_left_surf,(0,sides['topleft'].get_height()))

		# right side
		right_height = size[1] - (sides['topright'].get_height() + sides['bottomright'].get_height())
		scaled_right_surf = pygame.transform.scale(sides['right'],(sides['right'].get_width(),right_height))
		image.blit(scaled_right_surf,(size[0] - sides['right'].get_width(),sides['topright'].get_height()))

		# bottom side
		bottom_width = size[0] - (sides['bottomleft'].get_width() + sides['bottomright'].get_width())
		scaled_bottom_surf = pygame.transform.scale(sides['bottom'],(bottom_width,sides['bottom'].get_height()))
		image.blit(scaled_bottom_surf,(sides['topleft'].get_width(),size[1] - sides['bottom'].get_height()))
		
		# center color
		center_height = size[1] - (sides['top'].get_height() + sides['bottom'].get_height())
		center_width = size[0] - (sides['right'].get_width() + sides['left'].get_width())
		scaled_center = pygame.transform.scale(sides['center'],(center_width,center_height))
		image.blit(scaled_center,sides['topleft'].get_size())

		# return that image to the blocks or the player
		return image



 
