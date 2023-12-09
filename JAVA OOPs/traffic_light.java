import java.awt.*;  
import java.awt.event.*;  
import javax.swing.*;  
  
public class TrafficLight extends JFrame implements ActionListener {  
  
    private JButton redButton;  
    private JButton yellowButton;  
    private JButton greenButton;  
    private JPanel lightPanel;  
  
    public TrafficLight() {  
        setTitle("Traffic Light");  
        setSize(300, 400);  
        setDefaultCloseOperation(EXIT_ON_CLOSE);  
  
        redButton = new JButton("Red");  
        redButton.addActionListener(this);  
        yellowButton = new JButton("Yellow");  
        yellowButton.addActionListener(this);  
        greenButton = new JButton("Green");  
        greenButton.addActionListener(this);  
  
        lightPanel = new JPanel();  
        lightPanel.setBackground(Color.GRAY);  
  
        JPanel buttonPanel = new JPanel();  
        buttonPanel.setLayout(new GridLayout(1,3));  
        buttonPanel.add(redButton);  
        buttonPanel.add(yellowButton);  
        buttonPanel.add(greenButton);  
  
        add(lightPanel, BorderLayout.CENTER);  
        add(buttonPanel, BorderLayout.SOUTH);  
    }  
  
    public void actionPerformed(ActionEvent e) {  
        if (e.getSource() == redButton) {  
            lightPanel.setBackground(Color.RED);  
        } else if (e.getSource() == yellowButton) {  
            lightPanel.setBackground(Color.YELLOW);  
        } else if (e.getSource() == greenButton) {  
            lightPanel.setBackground(Color.GREEN);  
        }  
    }  
  
    public static void main(String[] args) {  
        TrafficLight tl = new TrafficLight();  
        tl.setVisible(true);  
    }  
}
