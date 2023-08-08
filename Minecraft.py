from ursina import *

app = Ursina()

def update():
    if held_keys['a']:
        player.x -= 4 * time.dt
    if held_keys['d']:
        player.x += 4 * time.dt
    if player.intersects(finish):
        print("You Win!")

player = Entity(model='cube', color=color.orange, scale=(1, 0.5, 1))
finish = Entity(model='cube', color=color.green, scale=(1, 0.5, 1), y=3)
ground = Entity(model='cube', color=color.white, scale=(10, 0.5, 1), y=-3)
app.run()