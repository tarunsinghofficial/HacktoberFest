package front_end_pc;
	import java.awt.*;
	import javax.swing.border.Border;

	public class RoundedBorder implements Border {

	    private int radius;
        private Color color;

	    RoundedBorder(int radius,Color col) {
	        this.radius = radius;
	        this.color=col;
	    }


	    public Insets getBorderInsets(Component c) {
	        return new Insets(this.radius+1, this.radius+1, this.radius+2, this.radius);
	    }


	    public boolean isBorderOpaque() {
	        return true;
	    }


	    public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) 
	    {
	        if(this.color.equals(Color.GREEN))
	        {
	          Graphics2D obj=(Graphics2D)(g);
	          obj.setStroke(new BasicStroke(5));
	        }
	    	g.setColor(this.color);
	    	g.drawRoundRect(x, y, width-1, height-1, radius, radius);
	    }
}


