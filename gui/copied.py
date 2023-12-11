import pygame
import sys
from communications import send_lines, init_serial

# Initialize Pygame
pygame.init()
arduino = init_serial('COM10')
# Set up display
width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Simple Line Drawing Tool")

# Colors
black = (0, 0, 0)
white = (255, 255, 255)
red = (255, 0, 0)

# Line variables
drawing = False
start_pos = None
end_pos = None
lines = []

# Button variables
button_rect = pygame.Rect(width - 100, 10, 90, 30)
button_font = pygame.font.Font(None, 24)
button_text = button_font.render("Send Coords", True, black)

# Main game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        
        elif event.type == pygame.MOUSEBUTTONDOWN and button_rect.collidepoint(pygame.mouse.get_pos()):
            # Check if the button is clicked
            print("Line Coordinates:")
            for line in lines:
                print(f"Start: {line[0]}, End: {line[1]}")
            send_lines(lines, arduino)
            
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if not drawing:
                # Start drawing
                start_pos = pygame.mouse.get_pos()
                drawing = True
            else:
                # Stop drawing
                end_pos = pygame.mouse.get_pos()
                drawing = False
                # Store the line coordinates
                lines.append((start_pos, end_pos))
                # print(lines)
        

    # Set background color to white
    screen.fill(white)
    
    # Draw existing lines
    for line in lines:
        pygame.draw.line(screen, black, line[0], line[1], 2)

    # Draw the current line being drawn
    if drawing:
        pygame.draw.line(screen, black, start_pos, pygame.mouse.get_pos(), 2)

    # Draw the button
    pygame.draw.rect(screen, red, button_rect)
    screen.blit(button_text, (width - 95, 15))

    # Update the display
    pygame.display.flip()

# Quit the game
pygame.quit()



