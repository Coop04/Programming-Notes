# uvicorn main:app --reload (to run the file)

from fastapi import FastAPI

app = FastAPI()


@app.get('/')
async def hello_world():
    return {"Hello": "World"}