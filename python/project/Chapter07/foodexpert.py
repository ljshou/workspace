class FoodExpert:

    def init(self):
        self.goodFood = []

    def addGoodFood(self, food):
        self.goodFood.append(food)

    def likes(self, x):
        return x in self.goodFood

    def prefers(self, x, y):
        x_rating = self.goodFood.index(x)
        y_rating = self.goodFood.index(y)
        if x_rating > y_rating:
            return y
        else:
            return x
