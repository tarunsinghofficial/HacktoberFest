import pygame

pygame.init()
pygame.mixer.init()

WIDTH = 1350
HEIGHT = 690
size = (WIDTH, HEIGHT)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Breakout")
font = pygame.font.SysFont('Constantia', 30)
clock = pygame.time.Clock()
FPS = 60
cols = 6
rows = 6

WHITE = (255, 255, 255)
GREY = (212, 210, 212)
BLACK = (0, 0, 0)
BLUE = (0, 97, 148)

RED = (162, 8, 0)
ORANGE = (183, 119, 0)
GREEN = (0, 127, 33)
YELLOW = (197, 199, 37)
text_col = (234, 218, 184)
score = 0
balls = 1
velocity = 4
game_over = 0
live_ball = False

paddle_width = 115
paddle_height = 20

all_sprites_list = pygame.sprite.Group()

brick_sound = pygame.mixer.Sound('sounds/brick.wav')
paddle_sound = pygame.mixer.Sound('sounds/paddle.wav')
wall_sound = pygame.mixer.Sound('sounds/wall.wav')





def draw_text(text, font, text_col, x, y):
    img = font.render(text, True, text_col)
    screen.blit(img, (x, y))

class Brick(pygame.sprite.Sprite):

    def __init__(self):
        self.width = WIDTH // cols
        self.height = 50

all_bricks = pygame.sprite.Group()
brick_width = 217
brick_height = 35
x_gap = 7
y_gap = 5
wall_width = 5
    def bricks(self):
            self.blocks = []
            #define an empty list for an individual block
            block_individual = []
            for row in range(rows):
                #reset the block row list
                block_row = []
                #iterate through each column in that row
                for col in range(cols):
                    #generate x and y positions for each block and create a rectangle from that
                    block_x = col * self.width
                    block_y = row * self.height
                    rect = pygame.Rect(block_x, block_y, self.width, self.height)
                    #assign block strength based on row
                    if row < 2:
                        strength = 3
                    elif row < 4:
                        strength = 2
                    elif row < 6:
                        strength = 1
                    #create a list at this point to store the rect and colour data
                    block_individual = [rect, strength]
                    #append that individual block to the block row
                    block_row.append(block_individual)
                #append the row to the full list of blocks
                self.blocks.append(block_row)


        def draw_bricks(self):
            for row in self.blocks:
                for block in row:
                    #assign a colour based on block strength
                    if block[1] == 3:
                        block_col = block_blue
                    elif block[1] == 2:
                        block_col = block_green
                    elif block[1] == 1:
                        block_col = block_red
                    pygame.draw.rect(screen, block_col, block[0])
                    pygame.draw.rect(screen, bg, (block[0]), 2)


brick_wall = bricks()




class Paddle(pygame.sprite.Sprite):

    def __init__(self, color, width, height):
        super().__init__()
        self.image = pygame.Surface([width, height])
        pygame.draw.rect(self.image, color, [0, 0, width, height])
        self.rect = self.image.get_rect()

    def moveRight(self, pixels):
        self.rect.x += pixels
        if self.rect.x > WIDTH - wall_width - paddle_width:
            self.rect.x = WIDTH - wall_width - paddle_width

    def moveLeft(self, pixels):
        self.rect.x -= pixels
        if self.rect.x < wall_width:
            self.rect.x = wall_width


class Ball(pygame.sprite.Sprite):

    def __init__(self, color, width, height):
        super().__init__()
        self.image = pygame.Surface([width, height])
        pygame.draw.rect(self.image, color, [0, 0, width, height])
        self.rect = self.image.get_rect()
        self.velocity = [velocity, velocity]

    def update(self):
        self.rect.x += self.velocity[0]
        self.rect.y += self.velocity[1]

    def bounce(self):
        self.velocity[0] = self.velocity[0]
        self.velocity[1] = -self.velocity[1]


paddle = Paddle(GREY, paddle_width, paddle_height)
paddle.rect.x = WIDTH // 2 - paddle_width // 2
paddle.rect.y = HEIGHT - 65

ball = Ball(WHITE, 10, 10)
ball.rect.x = WIDTH // 2 - 5
ball.rect.y = HEIGHT - 75







all_sprites_list.add(paddle)
all_sprites_list.add(ball)


def main(score, balls):

    step = 0

    run = True
    while run:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            paddle.moveLeft(10)
        if keys[pygame.K_RIGHT]:
            paddle.moveRight(10)

        all_sprites_list.update()

        if ball.rect.y < 40:
            ball.velocity[1] = -ball.velocity[1]
            wall_sound.play()

        if ball.rect.x >= WIDTH - wall_width - 10:
            ball.velocity[0] = -ball.velocity[0]
            wall_sound.play()

        if ball.rect.x <= wall_width:
            ball.velocity[0] = -ball.velocity[0]
            wall_sound.play()

        if ball.rect.y > HEIGHT:
            ball.rect.x = WIDTH // 2 - 5
            ball.rect.y = HEIGHT // 2 - 5
            ball.velocity[1] = ball.velocity[1]
            balls += 1
            if balls == 4:
                font = pygame.font.Font('text_style/DSEG14Classic-Bold.ttf', 70)
                text = font.render("GAME OVER", 1, WHITE)
                text_rect = text.get_rect(center=(WIDTH / 2, HEIGHT / 2))
                screen.blit(text, text_rect)
                pygame.display.update()
                pygame.time.wait(2000)
                run = False

        if pygame.sprite.collide_mask(ball, paddle):
            ball.rect.x += ball.velocity[0]
            ball.rect.y -= ball.velocity[1]
            ball.bounce()
            paddle_sound.play()

        brick_collision_list = pygame.sprite.spritecollide(ball, all_bricks, False)
        for brick in brick_collision_list:
            ball.bounce()
            brick_sound.play()
            if len(brick_collision_list) > 0:
                step += 1
                for i in range(0, 448, 28):
                    if step == i:
                        ball.velocity[0] += 1
                        ball.velocity[1] += 1
            if 380.5 > brick.rect.y > 338.5:
                score += 1
                brick.kill()
            elif 338.5 > brick.rect.y > 294:
                score += 3
                brick.kill()
            elif 294 > brick.rect.y > 254.5:
                score += 5
                brick.kill()
            else:
                score += 7
                brick.kill()
            if len(all_bricks) == 0:
                font = pygame.font.Font('text_style/DSEG14Classic-Bold.ttf', 70)
                text = font.render("SCREEN CLEARED", 1, WHITE)
                text_rect = text.get_rect(center=(WIDTH / 2, HEIGHT / 2))
                all_sprites_list.add(ball)
                screen.blit(text, text_rect)
                pygame.display.update()
                pygame.time.wait(2000)
                run = False

        screen.fill(BLACK)


        font = pygame.font.Font('text_style/DSEG14Classic-Bold.ttf', 70)
        text = font.render(str(f"{score:03}"), 1, WHITE)
        screen.blit(text, (80, 520))
        text = font.render(str(balls), 1, RED)
        screen.blit(text, (1200,520))
        all_sprites_list.draw(screen)

        pygame.display.update()

        clock.tick(FPS)

    pygame.quit()


main(score, balls)
